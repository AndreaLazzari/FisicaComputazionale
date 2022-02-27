esatto=Log[0.1];

Do[
   approx = Normal[Series[ Log[1+x], {x,0,i}]]  /. x-> -0.9;

   
If[ Abs[ approx/esatto -1] < 0.0001,
    Print["ordine necessario=", i];
    Break[]
  ],

   
   {i,1,100}
   ];
