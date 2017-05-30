// Given two pots containing v1 and v2 liters of water, respectively,
// determine the effect of pouring v liters from the ﬁrst pot into the second.
void pour (float& v1, float& v2, float& v) {
  v1 -= v;
  v2 += v;
}
// Aliasing occurs when we call pour(x, y, x), because v1 and v would be both aliases of x