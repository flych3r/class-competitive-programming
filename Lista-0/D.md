# D - Vertical Histogram

Write a program to read four lines of upper case (i.e., all CAPITAL LETTERS) text input (no more than 72 characters per line) from the input file and print a vertical histogram that shows how many times each letter (but not blanks, digits, or punctuation) appears in the all-upper-case input. Format your output exactly as shown.

## Input

Lines 1..4: Four lines of upper case text, no more than 72 characters per line.

## Output

Lines 1..??: Several lines with asterisks and spaces followed by one line with the upper-case alphabet separated by spaces. Do not print unneeded blanks at the end of any line. Do not print any leading blank lines.

## Sample Input
```
THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!
```

## Sample Output

```
                            *
        *                   *
        *                   *     *   *
        *                   *     *   *
*       *     *             *     *   *
*       *     * *     * *   *     * * *
*       *   * * *     * *   * *   * * * *
*     * * * * * *     * * * * *   * * * *     * *
* * * * * * * * * * * * * * * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
```
