class Solution {
public:
    int ladderLength(string start, string target, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({start,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(start);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();

            if(word==target) return steps;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};