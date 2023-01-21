template <typename T>
bool arrays_are_equal(const T *m1, const T *m2, size_t size = NULL){
    if (size == NULL) {
        return true;
    }
    for (int i = 0; i < size; i++) {
        if (m1[i] != m2[i]) {
            return false;
        }
    }
    return true;
}