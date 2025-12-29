#include "renderobject.h"
#include <glad/glad.h>
#include <vector>

RenderObject::RenderObject ( std::vector<float> vertices )
{
  this->vertices = vertices;
  this->VAO = 0;
  this->VBO = 0;
};

RenderObject::~RenderObject ( )
{
    glDeleteVertexArrays ( 1, &VAO );
    glDeleteBuffers ( 1, &VBO );
};

RenderObject::RenderObject ( RenderObject && other ) noexcept
{
    this->VAO = other.VAO;
    this->VBO = other.VBO;
    this->vertices = std::move(other.vertices);


    other.VAO = 0;
    other.VBO = 0;
}

RenderObject& RenderObject::operator= ( RenderObject && other) noexcept
{

    if ( this != &other )
    {
        glDeleteVertexArrays ( 1, &VAO );
        glDeleteBuffers ( 1, &VBO );
        this->VAO = other.VAO;
        this->VBO = other.VBO;
        this->vertices = std::move(other.vertices); 
                                                    
        other.VAO = 0;
        other.VBO = 0;
    }
    return *this;
}


int RenderObject::init_buffers () {
    glGenVertexArrays ( 1, &this->VAO );
    glBindVertexArray ( this->VAO );

    glGenBuffers ( 1, &this->VBO );

    glBindBuffer ( GL_ARRAY_BUFFER, this->VBO );
    glBufferData ( GL_ARRAY_BUFFER, vertices.size() * sizeof ( float ) ,
               vertices.data(), GL_STATIC_DRAW );

    glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( float ), ( void * ) 0 );
    glEnableVertexAttribArray(0);

    glVertexAttribPointer ( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof ( float ),
                        (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray ( 1 );

    glBindVertexArray ( 0 );
    return 0;
};
