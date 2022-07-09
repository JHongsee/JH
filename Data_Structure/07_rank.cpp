#include <bits/stdc++.h>
using namespace std ;

struct Student {
	int n;
	string name;
	vector<int> scores;
};

vector<Student> Sreport;
int N;

void read_show(  ){
    int score  ;
    string sname ;

    cin >> N ;
    for(int i=0; i < N; i++){
        cin >> sname ;
        //cout << "\n" << sname ;
		Student a;
		a.name = sname;
		a.n = 0;
        while( 1 ){
            cin >> score ;
            a.scores.push_back(score);
            a.n++;
            sort(a.scores.begin(), a.scores.end());
            if( score == 0 ) {
				Sreport.push_back(a);
				break ;
            }
            //else cout << " " << score ;

       }
    } // end of for i

} // end of read_show( )

bool My_Rank(Student a, Student b) {
	if(a.n == b.n) {
		for(int i = 1; i < a.n; i++) {
			if(a.scores[i] != b.scores[i])
				return a.scores[i] > b.scores[i];
		}
		return b.name > a.name;
	}
	else
		return a.n > b.n;
}



int main () {

    read_show(  ) ;
	sort(Sreport.begin(), Sreport.end(), My_Rank);

	for(int i = 0; i < N; i++)
		cout << Sreport[i].name << endl;

    return 0;
}
