/*************************************************************************
       File: text_justification.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-05-10 15:34:20

Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

************************************************************************/
#include "tools.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        
        vector<vector<string>> lines;
        int len = 0;
        vector<string> line;
        for (int i = 0; i < words.size(); i++) {
            if (len + words[i].size() <= maxWidth) {
                len += words[i].size() + 1;
                line.push_back(words[i]);
            } else {
                lines.push_back(line);
                  
                line = vector<string>();
                line.push_back(words[i]);
                len = words[i].size() + 1;
            }
        }
        lines.push_back(line);
        // print(lines);
        for (int i = 0; i < lines.size(); i++) {
            int chars = 0;
            for (int j = 0; j < lines[i].size(); j++) {
                chars += lines[i][j].size();
            }
            
            string line;
            int space = (maxWidth - chars) / max((int)(lines[i].size() - 1), 1);
            for (int j = 0; j < lines[i].size(); j++) {
                line += lines[i][j];
                if (i != lines.size()-1) {
                    if (space * (lines[i].size() - 1) != maxWidth - chars) {
                        if (1 == lines[i].size()) {
                            line += string(space, ' ');
                        } else if (j != lines[i].size()-1 && space * (lines[i].size() - 1) + j < maxWidth - chars) {
                            line += string(space+1, ' ');
                        } else if (j != lines[i].size()-1) {
                            line += string(space, ' ');
                        }
                    } else if (j != lines[i].size()-1) {
                        line += string(space, ' ');
                    }
                } else if (j != lines[i].size()-1) {
                    line += ' ';
                } else {
                    line += string(maxWidth-line.size(), ' ');
                }
            }
            
            ret.push_back(line);
            
        }
        
        return ret;
    }
};

int main() {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    
    // vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    // int maxWidth = 16;
    
    // vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain",
    //          "to","a","computer.","Art","is","everything","else","we","do"};
    // int maxWidth = 20;
    
    vector<string> r = Solution().fullJustify(words, maxWidth);
    print(r);
}
