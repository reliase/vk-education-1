#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

typedef struct {
    long long key;
    int value;
    int used;
} Slot;

typedef struct Group {
    char *key;
    const char **words;
    int count;
    int cap;
    struct Group *next;
} Group;

/* Задача 1 */

long long int_sqrt(long long n)
{
    long long l, r, mid;

    if (n < 0) {
        return -1;
    }
    if (n < 2) {
        return n;
    }

    l = 1;
    r = n / 2;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (mid <= n / mid) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

/* Задача 2 */

long long copy_time(long long n, long long x, long long y)
{
    long long fast, slow, l, r, mid;

    if (n <= 0) {
        return 0;
    }
    fast = x < y ? x : y;
    slow = x > y ? x : y;

    l = 0;
    r = (n - 1) * slow;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (mid / x + mid / y < n - 1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r + fast;
}

/* Задача 3 */

static int cmp_int(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int feed_animals(int *animals, int na, int *food, int nf)
{
    int fed = 0;
    int i;

    if (na <= 0 || nf <= 0) {
        return 0;
    }
    qsort(animals, (size_t)na, sizeof(int), cmp_int);
    qsort(food, (size_t)nf, sizeof(int), cmp_int);

    for (i = 0; i < nf && fed < na; i++) {
        if (food[i] >= animals[fed]) {
            fed++;
        }
    }
    return fed;
}

/* Задача 4 */

char extra_letter_count(const char *a, const char *b)
{
    int count[256] = {0};
    int i;
    unsigned char c;

    for (i = 0; a[i] != '\0'; i++) {
        count[(unsigned char)a[i]]++;
    }
    for (i = 0; b[i] != '\0'; i++) {
        c = (unsigned char)b[i];
        if (count[c] == 0) {
            return (char)c;
        }
        count[c]--;
    }
    return '\0';
}

char extra_letter_xor(const char *a, const char *b)
{
    unsigned char x = 0;
    int i;

    for (i = 0; a[i] != '\0'; i++) {
        x ^= (unsigned char)a[i];
    }
    for (i = 0; b[i] != '\0'; i++) {
        x ^= (unsigned char)b[i];
    }
    return (char)x;
}

/* Задача 5 */

static unsigned int hash_ll(long long key, unsigned int m)
{
    unsigned long long k = (unsigned long long)key;
    k ^= k >> 33;
    k *= 0xff51afd7ed558ccdULL;
    k ^= k >> 33;
    return (unsigned int)(k % m);
}

int two_sum(const int *data, int n, int target, int *i1, int *i2)
{
    unsigned int m, h;
    Slot *table;
    long long diff;
    int i;

    if (n < 2) {
        return 0;
    }
    m = 2u * (unsigned int)n + 1u;
    table = calloc(m, sizeof(Slot));
    if (table == NULL) {
        return -1;
    }

    for (i = 0; i < n; i++) {
        diff = (long long)target - data[i];

        h = hash_ll(diff, m);
        while (table[h].used) {
            if (table[h].key == diff) {
                *i1 = table[h].value;
                *i2 = i;
                free(table);
                return 1;
            }
            h = (h + 1) % m;
        }

        h = hash_ll(data[i], m);
        while (table[h].used) {
            h = (h + 1) % m;
        }
        table[h].key = data[i];
        table[h].value = i;
        table[h].used = 1;
    }

    free(table);
    return 0;
}

/* Задача 6 */

static char *make_key(const char *word)
{
    size_t count[256] = {0};
    size_t len = strlen(word);
    size_t i, pos = 0;
    int c;
    char *key = malloc(len + 1);

    if (key == NULL) {
        return NULL;
    }
    for (i = 0; i < len; i++) {
        count[(unsigned char)word[i]]++;
    }
    for (c = 0; c < 256; c++) {
        while (count[c] > 0) {
            key[pos++] = (char)c;
            count[c]--;
        }
    }
    key[pos] = '\0';
    return key;
}

static unsigned int hash_str(const char *s, unsigned int m)
{
    unsigned int h = 0;
    for (; *s != '\0'; s++) {
        h = h * 31u + (unsigned char)*s;
    }
    return h % m;
}

static void free_groups(Group **order, int ngroups)
{
    int k;
    for (k = 0; k < ngroups; k++) {
        free(order[k]->key);
        free(order[k]->words);
        free(order[k]);
    }
}

static void print_groups(Group **order, int ngroups)
{
    int k, j;
    printf("[");
    for (k = 0; k < ngroups; k++) {
        printf("%s[", k > 0 ? ", " : "");
        for (j = 0; j < order[k]->count; j++) {
            printf("%s\"%s\"", j > 0 ? ", " : "", order[k]->words[j]);
        }
        printf("]");
    }
    printf("]\n");
}

int group_anagrams(const char **words, int n)
{
    unsigned int m, h;
    Group **buckets, **order;
    Group *g;
    const char **tmp;
    char *key;
    int ngroups = 0;
    int i;

    if (n <= 0) {
        printf("[]\n");
        return 0;
    }

    m = 2u * (unsigned int)n + 1u;
    buckets = calloc(m, sizeof(Group *));
    order = malloc((size_t)n * sizeof(Group *));
    if (buckets == NULL || order == NULL) {
        free(buckets);
        free(order);
        return -1;
    }

    for (i = 0; i < n; i++) {
        key = make_key(words[i]);
        if (key == NULL) {
            goto fail;
        }

        h = hash_str(key, m);
        g = buckets[h];
        while (g != NULL && strcmp(g->key, key) != 0) {
            g = g->next;
        }

        if (g == NULL) {
            g = malloc(sizeof(Group));
            if (g == NULL) {
                free(key);
                goto fail;
            }
            g->cap = 4;
            g->count = 0;
            g->words = malloc((size_t)g->cap * sizeof(const char *));
            if (g->words == NULL) {
                free(key);
                free(g);
                goto fail;
            }
            g->key = key;
            g->next = buckets[h];
            buckets[h] = g;
            order[ngroups++] = g;
        } else {
            free(key);
        }

        if (g->count == g->cap) {
            tmp = realloc(g->words, (size_t)g->cap * 2 * sizeof(const char *));
            if (tmp == NULL) {
                goto fail;
            }
            g->words = tmp;
            g->cap *= 2;
        }
        g->words[g->count++] = words[i];
    }

    print_groups(order, ngroups);
    free_groups(order, ngroups);
    free(order);
    free(buckets);
    return 0;

fail:
    free_groups(order, ngroups);
    free(order);
    free(buckets);
    return -1;
}
