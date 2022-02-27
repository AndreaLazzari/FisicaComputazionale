(*
 \psi_{lm}(\theta\phi)  viene fattorizzata in   TH[th] PHI[phi]
 *)


eq2 = -D[ TH[th] PHI[phi] , {phi,2} ] == m^2 TH[th] PHI[phi];

sol2 = DSolve[ eq2, PHI[phi], phi ][[1]];
sol2 = sol2 /. {C[1]->1, C[2]->I};

sol22 = D[ sol2, {phi,2} ];



eq1 = -1/Sin[th] D[ Sin[th] D[ TH[th] PHI[phi], th] , th ] -
           1/Sin[th]^2 D[ TH[th] PHI[phi], {phi,2}] ==
           l (l+1) TH[th] PHI[phi];

eq1 = eq1 /. sol2 /. sol22;
  
sol1 = DSolve[ eq1, TH[th], th][[1]];
sol1 = sol1 /. {C[1]->1, C[2]->0};


Psi[th_, phi_, l_, m_]  = TH[th] PHI[phi] /. sol1 /. sol2;


grafico[l_,m_] := ParametricPlot3D[ r=Abs[ Psi[th,phi,l,m]];
				                      {r Sin[th] Sin[phi], r Sin[th] Cos[phi], r Cos[th]},
				                      {th,0, Pi}, {phi,0,Pi}
				                    ];


(*******)

(*

 x = Cos[th];
 d/dth    diventa  dx/dth d/dx  = -Sqrt[1-x^2] d/dx

 
 *)


  Derivative[1][f_][th] := -Sqrt[1-x^2] f'[x];                                               (*'*)
  Derivative[n_][f_][th] := -Sqrt[1-x^2] D[ Derivative[n-1][f][th] , x ];

subth = { Cos[th]->x, Sin[th]->Sqrt[1-x^2],
	       Csc[th]->1/Sqrt[1-x^2], Cot[th]->x/Sqrt[1-x^2],
     	       TH[th]->TH[x]};
