#version 120
#extension GL_ARB_texture_rectangle : enable

uniform sampler2DRect tex0;
uniform float amount;

void main(){
  vec2 pos = gl_TexCoord[0].st;

  vec4 b = texture2DRect(tex0, pos);
  
  gl_FragColor.rgb = b.rgb * b.a - amount;
  gl_FragColor.a = 1;
}

