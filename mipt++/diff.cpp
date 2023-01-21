template <typename T>
T* diff_of_arrays(const T *red, const T *ded, T *diff, int size, T def = 0){
    for (int i = 0; i < size; i++) {
        diff[i] = def;
    }
    for (int i = 0; i < size; i++) {
        diff[i] += (red[i] - ded[i]);
    }
    return diff;
}