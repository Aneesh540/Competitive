class TireNode:

    def __init__(self):
        self.wordindex = [None]*26
        self.isEnd = 0

    def increase_count(self):
        self.isEnd += 1


class Trie:
    
    def __init__(self):
        self.nullNode = TireNode()

    
    def add_word(self, word):
        
        pwn = self.nullNode
        
        for char in word:
            char_index = ord(char) - 97   # 97 is ord('a')
            
            assert(char_index >=0 and char_index <= 26)

            if pwn.wordindex[char_index] is None:   # if character is not present previously at that position
                # print('----> ', char)
                pwn.wordindex[char_index] = TireNode()
            
            pwn = pwn.wordindex[char_index]
        
        
        pwn.increase_count()

        print('"{}" added'.format(word))

        return True
    

    def search_word(self,word):
        pwn = self.nullNode

        for char in word:
            char_index = ord(char) - 97

            if pwn.wordindex[char_index] is None:
                print("word not present")
                return False
            
            pwn = pwn.wordindex[char_index]
            

        print("yes present count = {0}".format(pwn.isEnd))
        return pwn.isEnd
    
            

if __name__ == "__main__":
    
    diction = Trie()
    diction.add_word('aneesh')
    diction.add_word('aneesh')
    try:
        diction.add_word('aneej u')
    except:
        diction.search_word('aneesh')
        diction.search_word('aneej')
        diction.search_word('aneeshjain')

            
            

            