int i = 0;

while (i < 5) {
    if (i == 2)
        continue;   // BUG: i++ is never reached when i == 2
    printf("%d ", i);
    i++;
}