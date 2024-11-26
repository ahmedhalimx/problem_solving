int largestAltitude(int* gain, int gainSize) {
    int higst = 0, ps = 0;

    for (int i = 0; i < gainSize; ++i) {
        ps += gain[i];
        higst = (ps > higst)? ps : higst;
    }
    return higst;
}
