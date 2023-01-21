template <typename T, typename V>
void copy_array(const T *from, V *to, size_t size = 1) {
    for (int i = 0; i < size; i++) {
        to[i] = from[i];
    }
}