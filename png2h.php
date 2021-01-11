<?php

/*======================================================
	Script  : png2h.php
	Author  : rizapn@gmail.com
	Created : Jan 9, 2021
	Update  : Jan 9, 2021
--------------------------------------------------------
	To convert png font images to header file
	Usefull for font.h creation to include in the
	LED Panel project for arduino/esp8266 dev. board
--------------------------------------------------------
	Usage :
	> php png2h.php pngfile wfont hfont font0 flag
	- pngfile : font file in png format
	- wfont   : font width
	- hfont   : font height
	- font0   : the first font in the image
	- flag    : 0 = fixed width font output
				1 = multi-width font output
=======================================================*/

list($fpng,$wfont,$hfont,$font0,$flag) = explode(',',@$argv[1]);
list($width, $height) = getimagesize($fpng);
if (strlen($flag)==0) $flag = 0;
$src = imagecreatefrompng($fpng);
if (!$src) {
	print "Error opening $fpng !\r\n";
	exit;
}

$dot = 0;
for ($y=0; $y<$height; $y++) {
	for ($x=0; $x<$width; $x++) {
		$clr = imagecolorat($src, $x, $y);
		if ($clr>$dot) $dot = $clr;
		$IDX[$clr] = 1;
	}
}

selesai01:

$cidx = 1;
$y = 0;
while ($y<$height) {
	$x = 0;
	$OUT = array();
	if ($flag==1) $OUT[] = $wfont;
	$wfx = 0;
	while ($x<$width) {
		$dt = 0; $c = 0x8000;
		for ($yf=0; $yf<$hfont; $yf++) {
			$clr = imagecolorat($src, $x, $y+$yf);
			if ($clr==$dot) $dt |= $c;
			$c >>= 1;
		}
		if ($flag==0 || $dt!=0) {
			$OUT[] = ($dt>>8)&0xFF;
			if ($hfont>8) $OUT[] = $dt&0xFF;
			if ($dt>0) $wfx++;
		}
		$x++;
		if (($x%$wfont)==0) {
			if ($font0<32) $rem = 'chr('.$font0.')';
			else if ($font0==ord('\\')) $rem = 'backslash';
			else $rem = chr($font0);
			if ($flag==1) {
				$OUT[0] = $wfx;
				for ($i=$wfx; $i<$wfont; $i++) {
					$OUT[] = 0;
					if ($hfont>8) $OUT[] = 0;
				}
			}
			foreach ($OUT as $dt) printf("0x%02x,",$dt);
			print "  // $rem\r\n";
			$font0++;
			$OUT = array();
			if ($flag==1) $OUT[] = $wfont;
			$wfx = 0;
		}
	}
	$y += $hfont;
}

?>
