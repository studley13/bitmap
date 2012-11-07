testBitmap:		test_bitmap.o Canvas.o Color.o cmtools.o format/BMP.o
				c++ -o testBitmap test_bitmap.o Canvas.o Color.o cmtools.o format/BMP.o

test_bitmap.o:	test_bitmap.cpp
				c++ -c test_bitmap.cpp

Canvas.o:		Canvas.cpp
				c++ -c Canvas.cpp

Color.o:		Color.cpp
				c++ -c Color.cpp

format/BMP.o:	format/BMP.cpp
				c++ -c -o format/BMP.o format/BMP.cpp
