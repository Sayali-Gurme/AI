#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ColuTranspose 
{
    string plaintext;
    int col, row;
    void build() 
    {
        col = key.length();
        int len_plaintext = plaintext.length();
        if ((len_plaintext / col) * col == len_plaintext) {
            row = len_plaintext / col;
        } else {
            row = len_plaintext / col + 1;
        }
    }

public:
      string key;
      string encrypt_alphaKey() 
     {
        cout<<"Enter the key (e.g., 3214): ";
        cin>>key;
        cin.ignore();
        cout<<"Enter the plaintext: ";
        getline(cin, plaintext);
        build();
        
        vector<vector<char> > plainText_matrix(row, vector<char>(col, 'X'));
        vector<vector<char> > cypher_matrix(row,vector<char>(col,'X'));

        // Fill matrix with plaintext characters
        int index = 0; // To keep track of plaintext
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (index < plaintext.length()) {
                    plainText_matrix[i][j] = plaintext[index++];
                } else {
                    plainText_matrix[i][j] = 'X'; // Padding with 'X' if necessary
                }
            }
        }
        
        string result = "";
        for (int i = 0; i < key.length(); i++) {
            int Col_I = (key[i] - '0')- 1;
		 // Convert char to int (adjusting for 0-indexing)
            for (int j = 0; j < row; j++) {
            	cypher_matrix[j][Col_I]= plainText_matrix[j][i];
            }
        }


        for(int i=0;i<col;i++)
        {
        	for(int j=0;j<row;j++)
        	{	
        		if(cypher_matrix[j][i]!='X')
        			result+=cypher_matrix[j][i];
        		else
        			result+='.';
			}
		}   
        return result;
    }

    string decrypt_alphaKey(string ciphertext) {
        int textLength = ciphertext.length();
        vector<vector<char> > matrix(row, vector<char>(key.length()));

        // Fill matrix with ciphertext characters
        int index = 0;
        for (int j = 0; j < key.length(); j++) {
            int col_I = (key[j] - '0')- 1;
            index=col_I*row;// to get char from which curcol start
            for (int i = 0; i < row && index<ciphertext.length(); i++) {
                matrix[i][j] = ciphertext[index++];
            }
        }

        // Read characters row-wise to get the decrypted text
        string plaintext = "";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < key.length(); j++) 
            {
            //not to add X character
            if(matrix[i][j]!='.')
                plaintext += matrix[i][j];
            }
        }

        return plaintext;
    }
};

int main() {
    ColuTranspose cipher;
    string encryptedText = cipher.encrypt_alphaKey();
    cout << "Encrypted Text: " << encryptedText << endl;
    string decryptedText = cipher.decrypt_alphaKey(encryptedText);
    cout << "Decrypted Text: " << decryptedText << endl;
}
