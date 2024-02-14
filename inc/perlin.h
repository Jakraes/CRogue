// Credits to https://gist.github.com/nowl/828013

#ifndef PERLIN_H
#define PERLIN_H

extern long SEED;

int noise2(int x, int y);
float lin_inter(float x, float y, float s);
float smooth_inter(float x, float y, float s);
float noise2d(float x, float y);
float perlin2d(float x, float y, float freq, int depth);

#endif