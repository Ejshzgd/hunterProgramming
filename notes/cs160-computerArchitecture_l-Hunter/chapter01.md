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
**First,** partition the binary into groups of 3 and pad leading 0s if needed from right to left  
**Second,** convert each group to it's corresponding decimal value  
**Third,** concatenate the decimals  

Ex:


 




