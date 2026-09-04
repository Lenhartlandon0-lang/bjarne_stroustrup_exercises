//
//  Chapter4drill.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/20/26.
//
//  Honestly, this is a bit of a waste of time, given xcode doesnt let me compile bad examples.
#include "PPPheaders.h"

int main() {
    try {
        /*
        vector<int> v(5); for ( int i{}; i <= v.size(); ++i ) cout << "Success!\n";
         
        int i = 0; int j = 9; while (i < 10)  ++i;  if ( i > j ) cout << i <<  "Success!\n";
         
        int x = 2; double d = 4.5; if(d==2*x+0.5) cout << "Success!\n";
         
        string s = "Success!\n"; for (int i = 0; i<9; ++i) cout << s[i];
         
        int i = 0; while ( i < 10 ) ++i; if (9<i) cout << "success!\n";
         
        double x = 2; double d = 4.5; if (d==2*x+0.5) cout << "Success!\n";

        string s; cin >> s; cout << "
         
         Success!\n";
        */
        return 0;
    }
    catch( exception& e ) {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }
}
