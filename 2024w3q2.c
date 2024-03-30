

static void str_add(char *b, char *a, char *res, size_t size)
{
    int carry = 0;

    for (int i = 0; i < size; i++) {
        int tmp = (b[i] - '0') + (a[i] - '0') + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        res[i] = tmp + '0';
    }
}