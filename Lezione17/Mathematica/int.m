IntegraMonomio[expr_, var_] := Module[{risultato},

				      If[  MatchQ[ expr, w_. var^n_.],
					   prefattore = expr /. w_. var^n_. -> w;
					   esponente = expr /. w_. var^n_. -> n;
					   ];
				      
				      Which[ MatchQ[ expr, w_. var^n_.] && FreeQ[prefattore,var] &&
 					          FreeQ[ esponente, var] && esponente =!= -1,  
					          risultato = prefattore 1/(esponente+1) var^(esponente+1),

					     MatchQ[ expr, w_. var^n_.] && FreeQ[prefattore,var] &&
					     FreeQ[ esponente, var] && esponente === -1,
					     risultato = prefattore Log[var],
					     
					     FreeQ[ expr, var],
					     risultato = expr var,

					     True,
					     risultato = nonsointegrare[ expr, var]

					    ];
				      
				      risultato
];



myInt[expr_, var_] :=   Module[ {polinomio, risultato},

				polinomio = Expand[ expr];
				Which[ Head[ polinomio] === Plus,
				       risultato= Map[ IntegraMonomio[#,var ]&, polinomio] ,
				       
				       True,
				       risultato = IntegraMonomio[ expr, var ]

				       ];

				risultato
				
				];



