namespace Algoritimos {

public class Knapsack {



        public static int[,] Resolve (Objeto[] objetos) {

            int maximo = 9;
            int[,] sack = new int[objetos.Length, maximo ]; 

            Array.Clear(sack, 0, sack.Length);

            for (int i = 0; i < sack.GetLength(0); i++) {
                for (int j = 0; j < sack.GetLength(1); j++) {
                    if ( i == 0 || j == 0 ) {
                        sack[i , j] = 0;
                    }
                    else if (objetos[i].peso <= j) {
                        sack[i, j] = Math.Max(
                            objetos[i].valor +  sack[i - 1, j - objetos[i].peso],
                                                sack[i - 1, j]
                        );
                    }
                    else {
                        sack[i, j] = sack[i - 1, j]; 
                    }
                }
            }
            
            return sack;
        }

    }
}