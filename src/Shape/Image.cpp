#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include "Image.h"
#include "stb_image.h"
Image::Image(const std::string& name) {

	int nrChannels;
	unsigned char* data = stbi_load(("resources/textures/" + name).c_str(), &_width, &_height, &nrChannels, 4);
	if(data == nullptr){
		std::cout << "TROUDUC" << std::endl;
	}
	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);

}

int Image::getHeight() const {
	return _height;
}

int Image::getWidth() const {
	return _width;
}

GLuint& Image::getTextureId() {
	return _texture;
}
