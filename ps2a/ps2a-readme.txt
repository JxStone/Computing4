ps2-Jingxian Shi

step()
    No parameters. takes the stored seed and tap position and xor the left most bit and the bit at tap position. Moves every bit one position to the left and add the xor bit at the right most. Returns the right most bit as an integer

generate(int k)
    Take an integer parameter and generate k steps of the seed. returns a k-bit integer. Since the step function add a bit at the right most position and the seed is in binary representation, I simply declared a variable that keep tracks of the 0th(right most) position, adds one to the variable if it's one and multiply it by two every time the step function is called. In the end, the function returns the decimal representation of the k-bit integer

Unit tests
-longSeedString
    tests a 32 bit seed string tap at 22. The generate function should not be able to return an integer more than 32 bit. If the parameter passed into the generate function is more than 31, then the function should return -1.

-generateZeroBitInteger
    If the parameter passed into the generate function is zero, then the function should return zero and it should not be calling the step function since it generates 0 steps.
