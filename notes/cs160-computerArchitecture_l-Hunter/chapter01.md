# 1.1 Digital Systems
**Digital Systems:** Systemic ways to solve problems using digital technologies.  
Ex: SMART technologies, Digital clock  

**Discrete Information:** Sets with finite number of unique elements.  
Ex: Digits (1,2,3,4…,9), Letters (a,b,c … z)  

**Signals:** Some sort of physical quantity like voltage / electricity need to exist in order to represent discrete information.  

**Binary Representation:** Representing discrete information using 0s and 1s called a "Bit"

**Binary Codes:** Group of bits

# 1.2 Binary Numbers / Number systems
**Base-10 System:** Coefficients of a<sub>j</sub> can be any number from (0,1,2,3...9) & The subscript of j gives the powers of 10, 10<sup>j</sup> where j ∈ N | (∞,-∞)
>10<sup>5</sup> a<sub>5</sub> + 10<sup>4</sup> a<sub>4</sub> + 10<sup>3</sup> a<sub>3</sub> + 10<sup>2</sup> a<sub>2</sub> + 10<sup>1</sup> a<sub>1</sub> + 10<sup>0</sup> a<sub>0</sub> + 10<sup>-1</sup> a<sub>-1</sub> + 10<sup>-2</sup> a<sub>-2</sub> + 10<sup>-3</sup> a<sub>-3</sub> 

Ex: 7654 -> 7 x 10<sup>3</sup> + 6 x 10<sup>2</sup> + 5 x 10<sup>1</sup> + 4 x 10<sup>0</sup>  
0.10 -> 1 x 10<sup>-1</sup>

**Base-2 Systems:** Coefficients of a<sub>j</sub> can be any number from (0,1) & The subscript of j gives the powers of 2, 2<sup>j</sup> where j ∈ N | (∞,-∞)
>2<sup>5</sup> a<sub>5</sub> + 2<sup>4</sup> a<sub>4</sub> + 2<sup>3</sup> a<sub>3</sub> + 2<sup>2</sup> a<sub>2</sub> + 2<sup>1</sup> a<sub>1</sub> + 2<sup>0</sup> a<sub>0</sub> + 2<sup>-1</sup> a<sub>-1</sub> + 2<sup>-2</sup> a<sub>-2</sub> + 2<sup>-3</sup> a<sub>-3</sub> 

Ex: 101 -> 1 x 2<sup>2</sup> + 0 x 2<sup>1</sup> + 1 x 2<sup>0</sup> (The result is in base-10)

**Base-R System:** Coefficients of a<sub>j</sub> can be any number from (0...j-1) (aka Radix) & The subscript of j gives the powers of R, R<sup>j</sup> where j ∈ N | (∞,-∞)
>a<sup>j+2</sup> a<sub>j+2</sub> + a<sup>j+1</sup> a<sub>j+1</sub> + a<sup>j</sup> a<sub>j</sub> + a<sup>j-1</sup> a<sub>j-1</sub> + a<sup>j-2</sup> a<sub>j-2</sub> + a<sup>j-3</sup> a<sub>j-3</sub>

**1. All bases represent the same infinite set of number**  
2. The **higher the base**, the **more unique coefficients** there is and the **more compact the number representation** becomes as it requires fewer digits to express large values compared to lower bases  
3. In essences, it's just different ways to represent the same number  
4. Start at 0 from left to right  

**Hexadecimal, Base-16 System:** The letters of the alphabet are used
to supplement the 10 decimal digits when the base of the number is greater than 10.  
- Able to represent a binary number with 2 digits

| Coefficients | Hexadecimal Representation |
|:-------------|:--------------------------:|
|10            |A                           |
|11            |B                           |
|12            |C                           |
|15            |F                           |  

**Number System Arithmetic:** Follows the same rules for decimal numbers (base-10)

| Addition Binary Rules:         |
|:------------------------------:|
|0 + 0 = 0                       |
|1 + 0 = 1                       |
|1 + 1 = 10 write 0 carry 1      |
|1 + 1 + 1 = write 1 carry 1     |

Ex: 101101<sub>2</sub> + 100111<sub>2</sub> =  1010100<sub>2</sub>

| Subtraction Binary Rules:              |
|:--------------------------------------:|
|0 - 0 = 0                               |
|1 - 0 = 1                               |
|0 - 1 = 10 borrow until you find 1      |
|1 - 1 = 0                               |

Ex: 101101<sub>2</sub> − 100111<sub>2</sub> = 000110<sub>2</sub>  

**1.The resulting coefficients must be in the range of (0...r-1) in a Base-R System**
***
**Bit:** 1 bit = Represents 1 binary number: 0,1  
**Byte:** 8 bits = Represents one keyboard char
# 1.3 Number-Base Conversions
**Convert Base-10 to Base-R systems:**  
>When number is greater than 0:  
(41)<sub>10</sub>  
41 / R = x R y  (Divide by R until x = 0)

Ex: (41)<sub>10</sub> to Binary 

41 / 2 = 20 R 1  
20 / 2 = 10 R 0  
10 / 2 = 5 R 0  
5 / 2 = 2 R 1  
2 / 2 = 1 R 0  
1 / 2 = 0 R 1 (Stop when divisor is 0)  
(101001)<sub>2</sub> (Read from bottom up)  
>When the number is less than 0:  
(0.234)<sub>10</sub>  
0.234 * R = (Multiply by R until fraction part = 0)  
Start with 0.xxx

Ex:(0.234)<sub>10</sub> to Binary  

0.234 * 2 = 0.**468** (integer part = 0)  
0.468 * 2 = 0.**936** (integer part = 0)  
0.936 * 2 = 1.**872** (integer part = 1)  
≈(0.0011101)<sub>2</sub> (Read from top to bottom)  
**(Stop until fraction part = 0 or continue to get a better approximation)** 
# 1.4 Octal & Hexadecimal Numbers
**Convert binary to octal:**   
**First,** partition the binary into groups of 3 from right to left and pad leading 0s if needed  
**Second,** convert each group to it's corresponding decimal value  
**Third,** concatenate the decimals  

Ex:(10 110 001 101 011 . 111 100 000 110)<sub>2</sub> = (26153.7406)<sub>8</sub>  

**Convert binary to hexadecimal:**  
**First,** partition the binary into groups of 4 from right to left and pad leading 0s if needed  
**Second,** convert each group to it's corresponding hexadecimal value  
**Third,** concatenate the decimals 

Ex: (10 1100 0110 1011 . 1111 0010)<sub>2</sub> = (2C6B.F2)<sub>16</sub>

**Convert octal / hexadecimal to binary:** For each digit, convert to it's corresponding binary value. It should be a multiple of 3 or 4.

# 1.5 Complements of Numbers
**1.** Used to simplify subtraction in digital computers  
**2.** There are two types of complements for each base-r system: *the radix complement* and the *diminished radix complement*

**Diminished Radix Complement AKA [(r-1)'s complement]:** Base R-1 's complement 
>Given a number 'N' in base 'r' having n digits, the diminished radix complement is defined as: (r<sup>n</sup>-1) - N

**Computing Diminished Radix Complement:**  
Ex: **N = 546700 in Base-10**  
**Step 1: (r<sup>n</sup>-1)** = 100,000 - 1 = 999,999  
**The 9's complement of 546700 is 999,999 - 546700 = 453299**

**Shortcut for Binary:** It's diminished radix complement is **1's complement**  and to solve for it, just **flip each binary digit**

Ex: The 1's complement of 1011000 is 0100111 


**Radix Complement aka [(r's complement)]:** Take the diminished radix complement and add 1
>Given a number 'N' in base 'r' having n digits, the radix complement is defined as: [(r<sup>n</sup>-1) - N] + 1

Ex: **N = 012398 in Base-10**  
**Step 1:** (r<sup>n</sup>-1) = 100,000 - 1 = 999,999  
**Step 2:** The 9's complement of 012398 is 999,999 - 012398 = 987601  
**The 10's complement of 012398 is 987602**

**Shortcut for Binary:** Leave all least significant 0's and the first 1 unchanged and fliping the rest

Ex:  
- The 2’s complement of binary 1101100 is 0010100  
- The 2's complement of 0110111 is 1001001

The least significant 0's are all the 0s before the first '1' appears starting from the rightmost and moving left

**Subtraction of two n-digit unsigned numbers M - n in base r using complements:**  
**Step 1:** Find N's complement in base r  
**Step 2:** Add the complement to M  
**Step 3:**  If M >= N, the sum will produce an end carry, subtract the carry, r<sup>m</sup>, with r being the base and m being the number of digits in m

Ex: M = 72532 , N = 03250  
Step 1. 10's complement of N = 96750
Step 2. 72532 + 96750 = 169282  
Step 3. Since M > N, subtract the carry: 10<sup>5</sup>  
Answer: 69282  

- Pad with leading zeros if needed

If M < N, the sum will NOT produce an end carry. Instead, take the r's complement (radix complement) of the sum and add a negative sign in front

Ex: M = 3250 , N = 72532  
Step 1. 10's complement of N = 27468  
Step 2. 03250 + 27468 = 30718  
Step 3. Since M < N, the 10's complement of 30718 = 69282  and add a negative sign  
Final answer: -69282

# 1.6 Signed Binary Numbers
**Unsigned numbers:** Represents the number itself with no positive or negative sign

**Signed numbers:** Represents the number with a positive or negative sign determined by the leftmost bit. If the leftmost bit is 0, it's positive and if it's 1, negative *(Signed-magnitude convention)*

Ex:  
01001 is considered 9 (unsigned) and +9 (signed)  
11001 is considered 25 (unsigned) and -9 (signed) 

**Ways to represent signed negative numbers:**   
Ex:  
- Signed-magnitude rep: 10001001
- Signed-1's complement rep: 11110110
- Signed-2's complement rep: 11110111

*Signed-magnitude System:* If the leftmost bit is 0, it's positive and if it's 1, negative  
- Includes positive & negative numbers & 2 zeros

**Arithmetic Addition with signed-magnitude:**  
-If the **signs are the same**, we add the two magnitudes and give the sum the common sign  
-If the **signs are different**, we subtract the smaller magnitude with the larger and give the difference the sign of the larger magnitude  
Ex: (+25) + (-37) = -(37-25) = -12


*Signed-1's complement System:* Take the 1's complement of the positive number  
- Includes positive & negative numbers & 2 zeros

*Signed-2's complement System:* Take the 2's complement of the positive number  
- Includes positive & negative numbers & 1 zero 

**Reading a Signed-2's complement number:**  
-If the leftmost bit is 1, take the 2's complement, find the binary equivalent and change the sign to negative  
-If the leftmost bit is 0, find the binary equivalent and set the sign to positive

**Given a positive Signed-2's complement number -> Getting the negative equivalent**  OR **Given a negative Signed-2's complement number -> Getting the positive equivalent**  
Step 1. Take the 2's complement 
   
**Arithmetic Addition with Signed-2's complement (Binary):**  
-Convert all signed negative numbers into 2's complement and then add  
-Result will be in 2's complement  
-If there's a carry out, an extra bit that exceeds the number of bits, discard it.

Ex: (-1) 1111 + (+1) 0001 = 10000  
Final answer = 0000  

**Arithmetic Subtraction with Signed-2's complement (Binary):**  
Case 1. (+A) - (+B) = (+A) + (-B) -> Convert all numbers to it's Signed-2's complement form. Then change +B into -B. Lastly, add the numbers  

Case 2. (+A) - (-B) = (+A) + (+B) -> Convert all numbers to it's Signed-2's complement form. Then change -B into +B. Lastly, add the numbers  

-If there's a carry out, an extra bit that exceeds the number of bits, discard it.

**Overflow:** When the result of an operation cannot be represented within the fixed number of bits available. The result will wrap around.  
- **Same signs in -> different sign out = overflow**

  
**Note:** 
- Every bit must have a value. For eight bits, each bit position needs to have a value
- Positive numbers are written the same in both signed and unsigned systems
- Representing positive and negative 0 in signed-2's complement is the same: 0
- All negative numbers have 1 in the leftmost bit position

# 1.7 Binary Codes  
**Binary Codes:** When you have discrete information mapped into a sequence of binary digits. 

Ex: Mapping the letter 'W' into the ASCII's Binary equivalent: 01010111 

**Note:**
- n-bits binary code = up to 2<sup>n</sup> distinct combinations
- To get all possible n-bit combinations, just count in binary from 0 up to 2<sup>n</sup>-1, with each binary digit mapping to 1 distinct element in a discrete set
- The minimum number of bits to encode 2<sup>n</sup> distinct elements is n
- There's no maximum number of bits to encode 2<sup>n</sup>

**Binary-Coded Decimal (BCD):**  
- Each decimal digit is encoded with binary separately. Ex: 128 , you'll need 12 bits representing 1,2, and 8.  
- Each BCD representation is in groups of 4 bits
- You need 4k bits to represent a number with k decimal digits. Ex: 8 bits to represent all 2 decimal digit numbers (0-99)  
- Decimal digits 0-9 are the same in BCD and Binary  
- Whatever decimal digits that are not used have NO meaning in BCD  

**BCD Addition (Binary):**  
Step 1. Add the numbers as if they're in binary  
Case 1. If the sum is greater or equal to 1010 (10<sub>10</sub>), then add 0110 to obtain the result  
Case 2. If the result is less than 1010, no need to do anything!  

**Decimal Arithmetic / Subtraction with negative numbers:**  
- Positive numbers -> Leave as it is   
- Negative numbers -> Convert to it's 10's complement  
- Represent 0 with positive and 9 with negative  
- Discard the carry  

Ex: (+375) = 0 375  
(-240) = 9 760  
0 375 + 9 760 = 0 135  

**Weighted binary codes:** BCD 8421, 2421, 84-2-1  
Multiply each set of 4 digit binary code with the weighed factor and then add to get the result in decimal. Ex: 1001 in BCD 8421 = 1 * 8 + 0 * 4 + 0 * 2 + 1 * 1 = 9  

**Unweighted binary codes:** Excess-3  
Add 3 to each decimal digit, then convert to binary. Ex: 0+3 -> 0000 = 0011 in Excess-3, which is the equivalent to 3 in binary

**Property of Binary codes: Self-complementing:** 2421, Excess-3  
Lets you compute the 9’s complement of a decimal number by simply flipping the bits.  

**Gray code:**


  





 




