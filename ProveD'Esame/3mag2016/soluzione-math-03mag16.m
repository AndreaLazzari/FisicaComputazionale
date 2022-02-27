
(****  equazione differenziale ****)

sol1[a_,b_] = {x[t], y[t]} /.
              DSolve[ {x'[t] == 3 x[t] - y[t], y'[t] == x[t] + y[t],
                       x[0] == a, y[0] == b}, 
                      {x[t], y[t]}, 
                     t ];
gra[a_,b_] := Plot[ Evaluate[ sol1[a,b]], {t,0,1}];

grab = gra[1,-1];


sol1bis[a_,b_] = x[t] /.
  DSolve[ {x''[t] -4 x'[t] + 4 x[t] == 0,
           x'[0] == 3 a- b,
           x[0] == a},
         x[t], t];



(**** integrale di linea ****)


sol2 = DSolve[ { x'[t] == 2 x[t] - 1, y'[t] == x[t]^2 - y[t] },
               { x[t], y[t] },
              t][[1]];

campo[t_] = {y[t] - x[t]^2, 2 x[t] -1} /. sol2;
gamma = {x[t], y[t]} /. sol2 ;
derivgamma[t_] = D[ gamma, t];

integ = Integrate[ campo[w].derivgamma[w], {w,0,1}];




(****  congettura di Collatz ****)



a[0,n_] := n;

a[i_,n_] := a[i,n] = If[ EvenQ[a[i-1,n]], a[i-1,n]/2, 3 a[i-1,n] + 1 ];


prova[k_] := Do[ elem=a[i,k]; If[ elem===1, Return[i]; Break[]], {i,1,10000}]


punti = Table[ {j, prova[j]}, {j,1,10000}];

gra1 = ListPlot[ punti, PlotRange->All];

lista = Table[ prova[j], {j,1,10000}];

frequenza = Table[ {i,Count[lista,i]},         {i,1,Max[lista]}];

gra2 = ListPlot[ frequenza, PlotRange->All];

(**** ortonormalizzazione di Gram-Schmidt ****)

test = {{1,1,1}, {1,4,5}, {-2,7,9}};

base[vec_] := Table[ u[i] = vec[[i]] - 
                     Sum[  (vec[[i]].u[j-1])/(u[j-1].u[j-1]) u[j-1], {j,2,i}];
		     u[i] = u[i] / Sqrt[u[i].u[i]];
                     u[i],
                   {i,1,Length[ vec]}];


(**** scomposizione QR ****)
calcoloQ[M_] := Transpose[ base[ Transpose[M] ] ];

calcoloR[M_] := Table[If[ j>=i,
                            q =Transpose[calcoloQ[M]];
                            at=Transpose[M];
			    q[[i]].at[[j]],
                          0
                        ],
		      {i,1,Length[M]},{j,1,Length[M]}
                     ];

pm = {  
  {24, -102,8},
  {12, 334, -136},
  {-8, 48, -82}
};

testq = calcoloQ[ pm];
testr = calcoloR[ pm];




