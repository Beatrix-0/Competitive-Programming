```cpp
// problem : https://codeforces.com/problemset/problem/1741/D

#include<bits/stdc++.h>
using namespace std ;

int ans = 0 ;
vector < int > v;

// top dowm approach recursive way 
// can be done using bottom up ( merge type)
void yo ( int l1 , int r1 , int l2 , int r2 ){
    int leftMx = 0 ;
    for ( int i = l1 ; i <= r1 ; i++ ){
        leftMx = max ( leftMx , v[i]);
    }

    int rightMn = INT_MAX ; 
    for ( int i = l2 ; i <= r2 ; i++ ){
        rightMn = min ( rightMn , v[i]);
    }

    if( leftMx > rightMn ){
        // need swap between left and rigth segment
        int ind = l2 ;
        for ( int i = l1 ; i <= r1 ; i++ ){
            swap( v[i] , v[ind]);
            ind++;
        }
        ans++;
    }

    if ( l1 == r1 ) return ; 

    int mid1 = (l1 + r1)/2;
    int mid2 = (l2 + r2)/2;

    yo ( l1 , mid1 , mid1+1 , r1 ); 
    yo ( l2 , mid2 , mid2+1 , r2 ); 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc ; cin>> tc ;
    for ( int i = 1 ; i <= tc ; i++ ){
        int n ; cin >> n ;
        v.resize(n+1);
        for ( int i = 1 ; i <= n ; i++ ){
            cin >> v[i];
        }

        ans = 0 ;
        vector<int> tmp = v;
        sort(tmp.begin() + 1, tmp.end());
<?xml version="1.0" encoding="UTF-8"?>

<?import javafx.scene.control.TableColumn?>
<?import javafx.scene.control.TableView?>
<?import javafx.scene.layout.AnchorPane?>
<?import javafx.scene.text.Font?>
<?import javafx.scene.text.Text?>

<AnchorPane prefHeight="631.0" prefWidth="748.0" xmlns="http://javafx.com/javafx/23.0.1" xmlns:fx="http://javafx.com/fxml/1" fx:controller="bd.edu.seu.couriermanagmentsystem.Employee.EmployeeDeshboard.Features.empoloyeeLogController">
   <children>
      <AnchorPane layoutX="20.0" layoutY="20.0" prefHeight="586.0" prefWidth="731.0">
         <children>
            <Text layoutX="267.0" layoutY="77.0" strokeType="OUTSIDE" strokeWidth="0.0" text="Work Logs">
               <font>
                  <Font size="42.0" />
               </font>
            </Text>
            <Text layoutX="290.0" layoutY="153.0" strokeType="OUTSIDE" strokeWidth="0.0" text="Pickup Logs" wrappingWidth="169.505859375">
               <font>
                  <Font size="28.0" />
               </font>
            </Text>
            <Text layoutX="275.0" layoutY="388.0" strokeType="OUTSIDE" strokeWidth="0.0" text="Delivery Logs" wrappingWidth="169.505859375">
               <font>
                  <Font size="28.0" />
               </font>
            </Text>
            <TableView fx:id="pickupDataTable1" layoutX="44.0" layoutY="403.0" prefHeight="172.0" prefWidth="644.0">
               <columns>
                  <TableColumn fx:id="coNo1" prefWidth="25.0" text="No" />
                  <TableColumn fx:id="colTrack1" prefWidth="109.0" text="Tracking No" />
                  <TableColumn fx:id="colName1" prefWidth="116.0" text="Receiver's Name" />
                  <TableColumn fx:id="colWeight1" prefWidth="97.0" text="Weight" />
                  <TableColumn fx:id="colAdress1" prefWidth="192.0" text="Receiver's Adress" />
                  <TableColumn fx:id="colStatus1" prefWidth="104.0" text="Current Status" />
               </columns>
            </TableView>
         </children>
      </AnchorPane>
      <TableView fx:id="pickupDataTable" layoutX="60.0" layoutY="193.0" prefHeight="157.0" prefWidth="644.0">
         <columns>
            <TableColumn fx:id="coNo" prefWidth="25.0" text="No" />
            <TableColumn fx:id="colTrack" prefWidth="109.0" text="Tracking No" />
            <TableColumn fx:id="colName" prefWidth="116.0" text="Receiver's Name" />
            <TableColumn fx:id="colWeight" prefWidth="97.0" text="Weight" />
            <TableColumn fx:id="colAdress" prefWidth="192.0" text="Receiver's Adress" />
            <TableColumn fx:id="colStatus" prefWidth="104.0" text="Current Status" />
         </columns>
      </TableView>
   </children>
</AnchorPane>

        if ( v == tmp ){
            cout << 0 << '\n';
            continue;
        }

        int mid = (n+1)/2;
        yo(1 , mid , mid+1 , n );
        if( v == tmp ){
            cout << ans << '\n';
        }else {
            cout << -1 << '\n';
        }
    }
    
    return 0 ;
}
```