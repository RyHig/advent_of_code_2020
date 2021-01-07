# Notes for Day5.
- 128 rows on plane. (0 - 127)
- F(front) is lower half of rows.
- B(back) is upper half of rows.
### for example
`FBFBBFFRLR`

- F causes us to remove top half of (0 - 127), leaving bottom half (0 - 63)
- B causes us to remove bottom half of (0 - 63), leaving top half (32 - 63)
- F (32 - 63) -> (32 - 47)
- B (32 - 47) -> (40 - 47)
- B (40 - 47) -> (44 - 47)
- F (44 - 47) -> (44 - 45)
- F (44 - 45) -> (44)
We have the row, now we need to figure out the column we are in.
- Our first column value is R or upper half left. Causing us to go from (0 - 7) -> (4 - 7)
- Our second column value is L (lower half). (4 - 7) -> (4 - 5)
- Our last value is R. (4 - 5) -> (5)

After we have our row and our column. We need to multiply our row(44) by 8 and add our column(5) giving us 357 our seat id.
