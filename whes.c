/*
    Copyright (C) 2022  ikozyris
    Copyright (C) 2022  gkozyris
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <string.h>

    FILE* fp;
    size_t lines = 1;
    int ch, indx, m;
    char txt[100], fname[20];

int e()
{
    fp = fopen(fname,"r");
    if(fp  == NULL)
    {
        perror("fopen(): ");
        return -1;
    }
    while ((ch = getc(fp)) != EOF) 
    {
        if(ch=='\n')
            printf("$");
        putc(ch, stdout);

    }
    printf("$\n");    
    fclose(fp);
    return 0;
}

int r()
{
    fp = fopen(fname,"r");
    if(fp  == NULL)
    {
        perror("fopen(): ");
        return -1;
    }
    printf ("%03zu |", lines++);
    while ((ch = getc(fp)) != EOF) 
    {
        putchar(ch);
        if (ch == '\n')
        {            
            printf ("%03zu |", lines++);
        }
    }
    printf("\n");    
    fclose(fp);
    return 0;
}
int wrt()
{
    while((ch = getchar()) != '`')//reads until '`'
    {
        txt[indx++] = ch;
    }
    txt[indx] = '\0';
    fp = fopen(fname,"w");
    if(fp  == NULL)
    {
        perror("fopen(): ");
        return -1;
    }
    fprintf(fp, "%s", txt); //writes file
    fclose(fp); //closes file
    return 0;
}

int hlp() 
{
    printf( "Usage: yocto [FILE]... [OPTION]...                                            \n"
            "   -i, --interacive         interactive mode                                  \n"
            "   -w   --write             Write to file                                     \n"
            "   -r   --read              Read file                                         \n"
            "   -e, --show-ends          display $ at end of each line                     \n"
            "   -sn, --single-number     print total line number at the start              \n"
            "   --help     display this help and exit                                      \n"
            "   --version  output version information and exit                             \n"
            "Examples:                                                                     \n"
            "    yocto home/user/text.txt -sn  Read text.txt without printing the lines    \n"
            "    yocto -i       Start program in interactive mode                          \n"
	    "Documentation can be found on github.com/ikozyris/txt-editor/wiki             \n");
    return 0;
}
    
int sn()
{
    fp = fopen(fname,"r");
    if(fp  == NULL)
    {
        perror("fopen(): ");
        return -1;
    }
    else
    {
    while((ch=fgetc(fp))!=EOF)//getting number of lines
    {
        if(ch=='\n')
            lines++;
    }
    fclose(fp);
    fp = fopen(fname,"r"); //open file in read mode
    printf("lines:%ld\n-------\n", lines);
    while ((ch = getc(fp)) != EOF)
        putc(ch, stdout);
    fclose(fp);
    }
    printf("\n");
    return 0;
}