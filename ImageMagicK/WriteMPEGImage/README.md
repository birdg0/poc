```
$ identify -version
Version: ImageMagick 7.0.5-6 Q16 x86_64 2017-05-02 http://www.imagemagick.org
```

Recursive calls are too deep to cause stack overflow in WriteMPEGImage.
```
case 0:
{
  Image
    *frame;
  ...
  status=WriteImage(write_info,frame,exception);
  ...
  break;
}
```

BackTrace:
```
pwndbg> bt
#0  _IO_vfprintf_internal (s=s@entry=0x7fffff7ff500, format=format@entry=0x7ffff6b05a86 "%.*g", ap=ap@entry=0x7fffff7ff6a0) at vfprintf.c:1312
#1  0x00007ffff72f2ca6 in ___vsnprintf_chk (s=s@entry=0x7fffff7ff790 "", maxlen=<optimized out>, maxlen@entry=4096, flags=flags@entry=1, slen=slen@entry=18446744073709551615, format=format@entry=0x7ffff6b05a86 "%.*g", args=args@entry=0x7fffff7ff6a0) at vsnprintf_chk.c:63
#2  0x00007ffff6957b56 in vsnprintf (__ap=0x7fffff7ff6a0, __fmt=0x7ffff6b05a86 "%.*g", __n=4096, __s=0x7fffff7ff790 "") at /usr/include/x86_64-linux-gnu/bits/stdio2.h:77
#3  FormatLocaleStringList (string=0x7fffff7ff790 "", length=4096, format=0x7ffff6b05a86 "%.*g", operands=operands@entry=0x7fffff7ff6a0) at MagickCore/locale.c:459
#4  0x00007ffff6957c3f in FormatLocaleString (string=string@entry=0x7fffff7ff790 "", length=length@entry=4096, format=format@entry=0x7ffff6b05a86 "%.*g") at MagickCore/locale.c:484
#5  0x00007ffff69e6017 in FormatMagickSize (size=size@entry=41, bi=bi@entry=MagickFalse, suffix=suffix@entry=0x7ffff6b73065 "B", length=length@entry=64, format=format@entry=0x7fffff801860 "") at MagickCore/string.c:1125
#6  0x00007ffff69c73d8 in AcquireMagickResource (type=type@entry=WidthResource, size=41) at MagickCore/resource.c:184
#7  0x00007ffff689c4aa in OpenPixelCache (image=image@entry=0x39b6550, mode=mode@entry=IOMode, exception=exception@entry=0x61b780) at MagickCore/cache.c:3473
#8  0x00007ffff687d185 in GetImagePixelCache (image=0x39b6550, clone=clone@entry=MagickTrue, exception=0x61b780) at MagickCore/cache.c:1667
#9  0x00007ffff689fa1b in SyncImagePixelCache (image=<optimized out>, exception=<optimized out>) at MagickCore/cache.c:5224
#10 0x00007ffff694af7d in CloneImage (image=image@entry=0x399eff0, columns=41, rows=52, detach=detach@entry=MagickTrue, exception=exception@entry=0x61b780) at MagickCore/image.c:918
#11 0x00007ffff69530cf in CoalesceImages (image=image@entry=0x399eff0, exception=exception@entry=0x61b780) at MagickCore/layer.c:267
#12 0x00007ffff6a79f3a in WriteMPEGImage (image_info=0x39a57a0, image=0x399eff0, exception=0x61b780) at coders/mpeg.c:502
#13 0x00007ffff68c36aa in WriteImage (image_info=image_info@entry=0x399bd00, image=image@entry=0x399eff0, exception=exception@entry=0x61b780) at MagickCore/constitute.c:1183
#14 0x00007ffff6a7a1f1 in WriteMPEGImage (image_info=0x39847a0, image=0x397dff0, exception=0x61b780) at coders/mpeg.c:544
#15 0x00007ffff68c36aa in WriteImage (image_info=image_info@entry=0x397ad00, image=image@entry=0x397dff0, exception=exception@entry=0x61b780) at MagickCore/constitute.c:1183
#16 0x00007ffff6a7a1f1 in WriteMPEGImage (image_info=0x39637a0, image=0x395cff0, exception=0x61b780) at coders/mpeg.c:544
#17 0x00007ffff68c36aa in WriteImage (image_info=image_info@entry=0x3959d00, image=image@entry=0x395cff0, exception=exception@entry=0x61b780) at MagickCore/constitute.c:1183
#18 0x00007ffff6a7a1f1 in WriteMPEGImage (image_info=0x39427a0, image=0x393bff0, exception=0x61b780) at coders/mpeg.c:544
#19 0x00007ffff68c36aa in WriteImage (image_info=image_info@entry=0x3938d00, image=image@entry=0x393bff0, exception=exception@entry=0x61b780) at MagickCore/constitute.c:1183
#20 0x00007ffff6a7a1f1 in WriteMPEGImage (image_info=0x39217a0, image=0x391aff0, exception=0x61b780) at coders/mpeg.c:544
#21 0x00007ffff68c36aa in WriteImage (image_info=image_info@entry=0x3917d00, image=image@entry=0x391aff0, exception=exception@entry=0x61b780) at MagickCore/constitute.c:1183
#22 0x00007ffff6a7a1f1 in WriteMPEGImage (image_info=0x3900a30, image=0x38fa280, exception=0x61b780) at coders/mpeg.c:544
#23 0x00007ffff68c36aa in WriteImage (image_info=image_info@entry=0x38f6f90, image=image@entry=0x38fa280, exception=exception@entry=0x61b780) at MagickCore/constitute.c:1183
...
#806 0x00007ffff6a7a1f1 in WriteMPEGImage (image_info=0x61b910, image=0x639850, exception=0x61b780) at coders/mpeg.c:544
#807 0x00007ffff68c36aa in WriteImage (image_info=<optimized out>, image=0x639850, exception=0x61b780) at MagickCore/constitute.c:1183
#808 0x00007ffff7ba85b3 in Magick::Image::write (this=0x7fffffffdd30, imageSpec_=...) at Magick++/lib/Image.cpp:4899
#809 0x0000000000400d29 in main ()
#810 0x00007ffff71fd830 in __libc_start_main (main=0x400c90 <main>, argc=1, argv=0x7fffffffde98, init=<optimized out>, fini=<optimized out>, rtld_fini=<optimized out>, stack_end=0x7fffffffde88) at ../csu/libc-start.c:291
#811 0x0000000000400de9 in _start ()
```