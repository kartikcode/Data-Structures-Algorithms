//checks if its possible to split elements of vector arr into two sets of equal sums
bool findPartiion (vll arr, ll n)
{
    int sum = 0;
    int i, j;

    for (i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    bool part[sum / 2 + 1][n + 1];
    for (i = 0; i <= n; i++)
        part[0][i] = true;

    for (i = 1; i <= sum / 2; i++)
        part[i][0] = false;
    for (i = 1; i <= sum / 2; i++)
    {
        for (j = 1; j <= n; j++)
        {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j] ||
                             part[i - arr[j - 1]][j - 1];
        }
    }
    return part[sum / 2][n];
}
