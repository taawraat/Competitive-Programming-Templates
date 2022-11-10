void z_function(string s, vector<int>& z) {
    /*
        z vector stores values of z function
        z[i] will give the result of maximum prefix matched from index i
        for pattern search, just add the pattern to the beginning
        Ex: s = pattern + '$' + s;
    */
    int n = (int) s.length();
    z = vector<int>(n);
    z[0] = n;

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}
