#version 120
#extension GL_ARB_texture_rectangle : enable

uniform sampler2DRect tex0;
uniform sampler2DRect conidiaTex;

void main (void){
  vec2 pos = gl_TexCoord[0].st;

  vec4 hyphae = texture2DRect(tex0, pos);
  vec4 conidia = texture2DRect(conidiaTex, pos);

  vec4 outColor;
  if (conidia.a > 0) {
    outColor.rgb = hyphae.rgb * (1-conidia.a) + conidia.rgb * conidia.a;
    outColor.a = hyphae.a + conidia.a;
  } else {
    outColor = hyphae;
  }

  gl_FragColor = outColor;
}
