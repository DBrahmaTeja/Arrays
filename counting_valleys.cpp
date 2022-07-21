/*
Sample Input

8
UDDDUDUU
Sample Output

1
Explanation

If we represent _ as sea level, a step up as /, and a step down as \, the hike can be drawn as:

_/\      _
   \    /
    \/\/
The hiker enters and leaves one valley.
*/
int countingValleys(int steps, string path) {
       int i, level=0, valleys=0;
        for(i=0; i<steps; i++)
    {
        level += path[i] == 'U' ? 1 : -1;
        if(level == 0 && path[i] == 'U') valleys++;
    }
    
    return valleys;
    
}