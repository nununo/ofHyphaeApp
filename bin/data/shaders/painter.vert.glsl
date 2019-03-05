#version 150

uniform mat4 modelViewProjectionMatrix;
uniform samplerBuffer tex;
in vec4 position;

void main(){
  vec4 texPos = texelFetch(tex, gl_InstanceID);
  gl_Position = modelViewProjectionMatrix * position + texPos;
}
