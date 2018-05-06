#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int initializeglyphmap( std::map<char,int> &glyphmap, int glyphlen, char *glyph)
{
    char c = 0;
    for(int i=0;i<glyphlen;i++)
    {
        c = glyph[i];
        glyphmap[c] = -1;
    }
    return 1;
}

int  resetglyphmap(std::map<char,int> &glyphmap)
{

    for( auto &itr: glyphmap )
        itr.second = -1;
    return 1;
}

int appearanceCount(int input1,int input2,char* input3,char* input4)
{
    //Write code here
    int glyphlen = input1;
    int sequencelen = input2;
    char *glyph = input3;
    char *sequence = input4;
    int occurrences = 0;
    int glyphcntr = 0;
    std::map<char,int> glyphmap ;
    initializeglyphmap(glyphmap,glyphlen,glyph);
    int startpos = 0;
    for( int i = 0; i < sequencelen; i++)
    {
    
        if(glyphmap.find(sequence[i])!= glyphmap.end())
        {
            if(glyphmap[sequence[i]] == -1 )
            {
                glyphmap[sequence[i]] = i;
                glyphcntr++;
                
                if(glyphcntr == 1)
                    startpos = i;
            }
            else    // letter already processed, start matching again from last found pos+1.
            {
                glyphcntr = 0;
                i = glyphmap[sequence[i]];
                resetglyphmap(glyphmap);
                continue;
            }
            
            if( glyphcntr == glyphlen )
            {
                i=startpos;
                glyphcntr = 0;
                resetglyphmap(glyphmap);
                occurrences++;
            }
                
        }
        else
        {
            glyphcntr = 0;
        }
    
    }
    
    return occurrences;
    
}


int main() {
    int output = 0;
    int ip1;
    scanf("%d", &ip1);
    int ip2;
    scanf("%d", &ip2);
    char* ip3;
    ip3 = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",ip3);
    char* ip4;
    ip4 = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",ip4);
    output = appearanceCount(ip1,ip2,ip3,ip4);
    printf("%d\n", output);
    return 0;
}