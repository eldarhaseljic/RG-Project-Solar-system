#ifndef TEXTURE_HPP
#define TEXTURE_HPP value
#include <fstream>
#include <assert.h>

using namespace std;

struct Image {

	char* pixel_data;
	int width;
	int height;

	Image(char* data, int w, int h)
	{
	    pixel_data = data;
	    width  = w;
	    height = h;
	}

	~Image()
	{
	    delete [] pixel_data;
	}

};

GLuint Texture;
Image* planet;
GLUquadricObj *ball;

template<class T>
struct auto_array
{
    T* array;
    bool isReleased;

    auto_array(T* array_ = NULL) :
        array(array_), isReleased(false) {}

    ~auto_array()
    {
        if (!isReleased && array != NULL)
        {
        delete[] array;
        }
    }

    T* release()
    {
        isReleased = true;
        return array;
    }
};

int readInt(ifstream &input)
{
    char buffer[4];
    input.read(buffer, 4);
    return (int)(((unsigned char)buffer[3] << 24) |
        ((unsigned char)buffer[2] << 16) |
        ((unsigned char)buffer[1] << 8) |
        (unsigned char)buffer[0]);
}

Image* loadBMP(const char* filename)
{
	ifstream input;
	input.open(filename, ifstream::binary);
    char buffer[2];
	input.read(buffer, 2);
	input.ignore(8);

	int dataOffset = readInt(input);
	int headerSize = readInt(input);
	int width= readInt(input);
    int height = readInt(input);
    input.ignore(2);

	int bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
	int size = bytesPerRow * height;

	auto_array<char> pixels(new char[size]);
	input.seekg(dataOffset, ios_base::beg);
	input.read(pixels.array, size);

	auto_array<char> pixels2(new char[width * height * 3]);
	for (int y = 0; y < height; ++y)
    {
		for (int x = 0; x < width; ++x)
		{
			for (int c = 0; c < 3; ++c)
			{
				pixels2.array[3 * (width * y + x) + c] =
                pixels.array[bytesPerRow * y + 3 * x + (2 - c)];
			}
		}
	}

	input.close();
	return new Image(pixels2.release(), width, height);
}

void tex (int p)
{
    if(p == 1)
        planet = loadBMP("C:/Users/Haselja/Desktop/eldar_haseljic_zavrsniprojekat/Projekat/Textures/sun.bmp");
    if(p == 2)
        planet = loadBMP("C:/Users/Haselja/Desktop/eldar_haseljic_zavrsniprojekat/Projekat/Textures/earth.bmp");
    if(p == 3)
        planet = loadBMP("C:/Users/Haselja/Desktop/eldar_haseljic_zavrsniprojekat/Projekat/Textures/moon.bmp");

    glGenTextures ( 1, &Texture );
    glBindTexture ( GL_TEXTURE_2D, Texture);
    glTexImage2D  ( GL_TEXTURE_2D, 0, GL_RGB,
                  planet -> width , planet -> height ,
                  0 , GL_RGB , GL_UNSIGNED_BYTE , planet -> pixel_data );
    delete planet;

    glColor3f(1,1,1);
    ball=gluNewQuadric();
    gluQuadricNormals(ball, GLU_SMOOTH);
    glBindTexture(GL_TEXTURE_2D, Texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluQuadricTexture(ball, 1);
    if ( p == 1)
        gluSphere(ball,1.8,120,60);
    if ( p == 2)
        gluSphere(ball,0.6,60,30);
    if ( p == 3)
        gluSphere(ball,0.18,30,15);
    gluDeleteQuadric(ball);
}

#endif // TEXTURE_HPP
