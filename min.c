int min(int *arr, size_t size) {
        if (size == 0) { return INT_MAX; }

        int result = arr[0];

        for (size_t i = 1; i < size; i++) {
                if (arr[i] < result) {
                        result = arr[i];
                }
        }

        return result;