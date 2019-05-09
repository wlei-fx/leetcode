/*************************************************************************
       File: word_ladder_ii.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-05-07 11:11:59

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

************************************************************************/
#include <vector>
#include <string>
#include <iostream>
#include <list>
using namespace std;

template <typename T>
void print(vector<vector<T>> &r) {
    for (int i = 0; i < r.size(); i++) {
        cout<<"[";
        for (int j = 0; j < r[i].size(); j++) {
            cout<<r[i][j];
            if (j < r[i].size()-1) {
                cout<<"->";
            }
        }
        cout<<"]"<<endl;
    }
}

void print(vector<vector<int>> &r, vector<string> &wordList) {
    for (int i = 0; i < r.size(); i++) {
        cout<<"[";
        for (int j = 0; j < r[i].size(); j++) {
            cout<<wordList[r[i][j]];
            if (j < r[i].size()-1) {
                cout<<"->";
            }
        }
        cout<<"]"<<endl;
    }
}

void print(vector<int> &r, vector<string> &wordList) {
    cout<<"[";
    for (int j = 0; j < r.size(); j++) {
        cout<<wordList[r[j]];
        if (j < r.size()-1) {
            cout<<"->";
        }
    }
    cout<<"]"<<endl;
}

class SolutionO {
public:
    bool isLadder(string a, string b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (1 == diff) {
                    return false;
                }
                
                diff++;
            }
        }
        
        return true;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        vector<string> p;
        p.push_back(beginWord);
        ret.push_back(p);
        
        int shortest = INT_MAX;
        for (int i = 0; i < ret.size(); i++) {
            // print(ret);
            if(ret[i].back() == endWord) {
                break;
            }
            
            for (auto jt = wordList.begin(); jt != wordList.end(); ) {
                if (*jt == beginWord) {
                    jt = wordList.erase(jt);
                    continue;
                }
                if (isLadder(ret[i].back(), *jt)) {
                    vector<string> t(ret[i]);
                    t.push_back(*jt);
                    ret.push_back(t);
                    if (*jt == endWord) {
                        shortest = min(shortest, (int)t.size());
                        break;
                    } else {
                        for (int k = i+1; k < ret.size() && ret[k].size() < t.size(); k++) {
                            if (isLadder(ret[k].back(), *jt)) {
                                vector<string> t(ret[k]);
                                t.push_back(*jt);
                                ret.push_back(t);
                            }
                        }
                        jt = wordList.erase(jt);
                    }
                } else {
                    ++jt;
                }
            }
        }
        
        for (auto it = ret.begin(); it != ret.end(); ) {
            if ((*it).back() != endWord || (*it).size() > shortest) {
                it = ret.erase(it);
            } else {
                ++it;
            }
        }
        
        return ret;
    }
};

class Solution {
public:
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<int>> ret;
        vector<vector<int>> toFix;  // 当发现相同的后缀时，放弃搜索，最后补全，以提升效率
        vector<int> depth = vector<int>(wordList.size(), INT_MAX);
        vector<vector<int>> adj(wordList.size(), vector<int>());
        
        for (int i = 0; i < wordList.size(); i++) {
            int diff = 0;
            for (int k = 0; k < beginWord.size() && diff <= 1; k++) {
                diff += beginWord[k] == wordList[i][k] ? 0 : 1;
            }
            if (1 == diff) {
                vector<int> p(1, i);
                ret.push_back(p);
                depth[i] = 1;
            }
            
            for (int j = i+1; j < wordList.size(); j++) {
                if (wordList[i] == beginWord || wordList[j] == beginWord) {
                    continue;
                }
                
                int diff = 0;
                for (int k = 0; k < wordList[i].size() && diff <= 1; k++) {
                    diff += wordList[i][k] == wordList[j][k] ? 0 : 1;
                }
                if (1 == diff) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        while (!ret.empty() && wordList[ret.front().back()] != endWord) {
            // cout<<"start: "<<endl;
            // print(ret, wordList);
            // cout<<endl;
            
            vector<int> ct(ret.front());
            ret.erase(ret.begin());
            
            if (adj[ct.back()].empty()) {
                continue ;
            }
            
            for (int j = 0; j < adj[ct.back()].size(); j++) {
                vector<int> t(ct);

                if (depth[adj[t.back()][j]] <= t.size()) {  // 已发现到达该单词更短的路径，当前路径加入该单词也不会最短
                    continue;
                } else if (depth[adj[t.back()][j]] == t.size()+1 && wordList[adj[t.back()][j]] != endWord) { // 已发现到达该单词最短的路径，后面补齐即可，不必重复搜索
                    t.push_back(adj[t.back()][j]);
                    toFix.push_back(t);
                    continue;
                }
                
                t.push_back(adj[t.back()][j]);
                depth[t.back()] = t.size();
            
                ret.push_back(t);
            }
            
            // cout<<"toFix: "<<endl;
            // print(toFix, wordList);
            // cout<<endl;
            // 
            // cout<<"end: "<<endl;
            // print(ret, wordList);
            // cout<<endl;
        }
        
        for (auto it = ret.begin(); it != ret.end(); ) {
            if (wordList[(*it).back()] != endWord) {
                it = ret.erase(it);
            } else {
                ++it;
            }
        }
        
        // cout<<"^^^^^^^^^^^^^^^^^^^^^^^^\ntoFix: "<<endl;
        // print(toFix, wordList);
        // cout<<endl;
        // 
        // cout<<"end: "<<endl;
        // print(ret, wordList);
        // cout<<endl;
        
        int retSize = ret.size(), ll = -1;
        for (int i = toFix.size()-1; i >= 0; i--) {
            if (ll != toFix[i].size()) {
                retSize = ret.size();
                ll = toFix[i].size();
            }
            for (int j = 0; j < retSize; j++) {
                if (toFix[i].size() < ret[j].size() && toFix[i].back() == ret[j][toFix[i].size()-1]) {
                    vector<int> tf(toFix[i]);
                    for (int k = tf.size(); k < ret[j].size(); k++) {
                        tf.push_back(ret[j][k]);
                    }
                    ret.push_back(tf);
                }
            }
        }
        
        // cout<<"end: "<<endl;
        // print(ret, wordList);
        // cout<<endl;
        
        vector<vector<string>> r;
        for (auto it = ret.begin(); it != ret.end(); ++it) {
            if (wordList[(*it).back()] == endWord) {
                vector<string> p;
                p.push_back(beginWord);
                for (int i = 0; i < (*it).size(); i++) {
                    p.push_back(wordList[(*it)[i]]);
                }
                r.push_back(p);
            }
        }
    
        return r;
    }
};

int main() {
    // string beginWord = "hit";
    // string endWord = "cog";
    // vector<string> wordList = 
    // {"hot","dot","dog","lot","log","cog"};
    // // {"hot","dot","dog","lot","log"};
    
    // string beginWord = "a";
    // string endWord = "c";
    // vector<string> wordList = {"a", "b", "c"};
    
    // string beginWord = "hot";
    // string endWord = "dot";
    // vector<string> wordList = {"hot","dot","dog"};
    
    // string beginWord = "red";
    // string endWord = "tax";
    // vector<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
    
    // string beginWord = "qa";
    // string endWord = "sq";
    // vector<string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    
    string beginWord = "nape";
    string endWord = "mild";
    vector<string> wordList = {"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"};
    
    cout<<"\nresult: \n";
    vector<vector<string>> r = Solution().findLadders(beginWord, endWord, wordList);
    print(r);
}
