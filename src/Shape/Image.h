#pragma once
#include <string>
#include <glad/glad.h>

class Image {
public:
	Image(const std::string& name);
	GLuint getTextureId() const;
	int getWidth() const;
	int getHeight() const;
private:
	GLuint _texture{};
	int _width{};
	int _height{};
};
