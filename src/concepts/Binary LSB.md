Absolutely, let's go through this step by step to explain how both of the formulas work for finding the **lowest significant bit (LSB)** of a number:

### Formula 1: `x & -x`

This formula is based on **two's complement** representation, which is how negative numbers are stored in most modern systems.

- **Two's complement** is the binary representation of negative numbers, where `-x` is represented by flipping all the bits of `x` and adding `1`.

#### Why does `x & -x` work?

When we perform `x & -x`, the result isolates the rightmost (least significant) bit that is set to `1`. This happens because:

- When we negate `x` to get `-x`, the bits flip after the rightmost `1` in `x`.
- This causes all the bits after the lowest `1` in `x` to become `0` in `-x`, but the lowest `1` stays the same in both `x` and `-x`.

So, `x & -x` effectively leaves only the lowest `1` bit in the result, and all other bits are cleared to `0`.

#### Example 1:

For `x = 12` (`1100` in binary):

1. **Binary representation of 12**: `1100`
2. **Two's complement of 12**: `-12 = ~1100 + 1 = 0011 + 1 = 0100`
3. **Perform `x & -x`**: `1100 & 0100 = 0100` (This is `4` in decimal, which is the lowest significant bit.)

#### Example 2:

For `x = 18` (`10010` in binary):

1. **Binary representation of 18**: `10010`
2. **Two's complement of 18**: `-18 = ~10010 + 1 = 01101 + 1 = 01110`
3. **Perform `x & -x`**: `10010 & 01110 = 00010` (This is `2` in decimal, which is the lowest significant bit.)

### Formula 2: `x & ~(x - 1)`

This formula also works to find the lowest significant bit of `x`, but it uses a different trick.

#### Why does `x & ~(x - 1)` work?

- When you subtract `1` from `x`, it turns the rightmost `1` in `x` into a `0` and flips all the bits to the right of it.
- Taking the bitwise NOT (`~`) of `(x - 1)` essentially flips all the bits, so all the bits up to and including the lowest set bit in `x` become `0`, and all the bits before it remain `1`.
- When you then do `x & ~(x - 1)`, the only bit that remains set is the lowest set bit in `x`, because it’s the only bit that differs between `x` and `x - 1`.

#### Example 1:

For `x = 12` (`1100` in binary):

1. **x - 1**: `12 - 1 = 11 = 1011` (in binary).
2. **NOT of (x - 1)**: `~1011 = 0100` (in binary).
3. **Perform `x & ~(x - 1)`**: `1100 & 0100 = 0100` (This is `4` in decimal, which is the lowest significant bit.)

#### Example 2:

For `x = 18` (`10010` in binary):

1. **x - 1**: `18 - 1 = 17 = 10001` (in binary).
2. **NOT of (x - 1)**: `~10001 = 01110` (in binary).
3. **Perform `x & ~(x - 1)`**: `10010 & 01110 = 00010` (This is `2` in decimal, which is the lowest significant bit.)

### Conclusion:

- Both `x & -x` and `x & ~(x - 1)` isolate the least significant `1` bit of a number.
- These formulas are widely used because they are efficient and work in constant time, regardless of the number of bits in `x`.
