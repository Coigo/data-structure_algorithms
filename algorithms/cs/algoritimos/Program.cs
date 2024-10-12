using System.Globalization;
using System.Reflection.PortableExecutable;
using System.Runtime.InteropServices;
using System.Xml.XPath;


namespace Algoritimos {

    public struct Objeto {
        public string nome { get; set; }
        public int valor { get; set; }
        public int peso { get; set; }
    }

    public struct Video {
        public int id { get; set; }
        public string[] tags { get; set; }
        public string   title { get; set; }
    }


    class Start {

        static void Main () {

            Video[] videos = new Video[7] {
                new Video { id= 1,tags = new[] { "Programacao", "TypeScript", "Node", "Tecnologia" }, title = "Aprenda typescript em um minuto" },
                new Video { id= 2,tags = new[] { "Cozinha", "Carne", "Panela", "Brasil" }, title = "Cozinhe carne de panela" },
                new Video { id= 3,tags = new[] { "Servidor", "Raspberry", "Brasil", "Tecnologia" }, title = "Monte o seu servidor em casa" },
                new Video { id= 4,tags = new[] { "Lol", "Jogos", "Brasil", "Zed" }, title = "Detonando o mid de Zedao" },
                new Video { id= 5,tags = new[] { "Politica", "Brasil", "Queimadas", "Lula" }, title = "Vai fazer o que Lulao" },
                new Video { id= 6,tags = new[] { "Danca", "Bale", "Casa", "Arte" }, title = "Dancando bale pelado em casa" },
                new Video { id= 7,tags = new[] { "Prank", "Trolagem", "Arvore", "Plantar" }, title = "Plantei maconha no quintal do meu vizinho" }
            };

            string[] usuarioCoisas = new string[3] {"Tecnologia", "Brasil", "Politica" }; 

            var matches = Teste(videos, usuarioCoisas);

            foreach (var match in matches) {
                Console.WriteLine($"{match.Value} matches no video {match.Key}");
            }

        }

        public static IEnumerable<KeyValuePair<int, int>> Teste (Video[] videos, string[] usuarioCoisas)   {

            var matches = new Dictionary<int, int>();

            for (int i = 0; i < videos.Length; i++) {

                int match = 0;
                for (int j = 0; j < usuarioCoisas.Length; j++) {
                    if ( videos[i].tags.Contains(usuarioCoisas[j]) ) {
                        match++;
                    }                    
                }

                matches[videos[i].id] = match;

            }
            
           return matches.OrderBy(m => m.Value);

        }

    } 

            // Objeto[] objetos = new Objeto[5] {

            //     new Objeto { nome = "abajur", peso = 1, valor= 500},
            //     new Objeto { nome = "celular", peso = 1, valor= 1500},
            //     new Objeto { nome = "ventilador",peso = 2, valor= 200},
            //     new Objeto { nome = "micro-ondas", peso = 3, valor= 2000},
            //     new Objeto { nome = "tv", peso = 5, valor= 3000},
            // };

            // int[,] resultado = Knapsack.Resolve(objetos);


            // for (int i = 0; i < resultado.GetLength(0); i++ ) {
            //     for (int j = 0; j < resultado.GetLength(1); j++ ) {
            //         Console.Write($"{resultado[i,j]}, ");
            //     }
            //         Console.Write("\n");
            // }
    

}   