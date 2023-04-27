class Solution {
public:
// Requires a bit of math magic, proof of fact essentially relies
// upon considering each a*b factor of n as a toggle on/off pair,
// so only values <= n that remain on after an execution will be those
// that have factor of form a*a (i.e. those with integer root)
    int bulbSwitch(int n) {
        return floor(sqrt(n));
    }
};
