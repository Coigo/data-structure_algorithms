const grafos = {
    "Eu": {
        nome: "Eu",
        seller: false, 
        relacoes: ["Jao"]   
    },
    "Jao": {
        nome: "Jao",
        seller: false, 
        relacoes: ["Fulano", "Ciclano"]   
    },
    "Fulano": {
        nome: "Fulano",
        seller: false, 
        relacoes: ["Ciclano"]   
    },
    "Ciclano": {
        nome: "Ciclano",
        seller: true, 
        relacoes: ["Jao"]   
    }
}

let seller = undefined;

const analized = [];
const toAnalize = [grafos["Eu"]];

const hasBeenAnalized = (atual) => {
    return analized.some(analizado => analizado.nome === atual.nome);
};

while (!seller && toAnalize.length > 0) {
    const atual = toAnalize.shift();
    
    if (!hasBeenAnalized(atual)) {
        console.log(atual);
        
        if (atual.seller) {
            seller = atual;
            break;
        } else {
            // Adiciona as relações ao array toAnalize, se existirem em grafos
            atual.relacoes.forEach(relacao => {
                if (grafos[relacao]) {
                    toAnalize.push(grafos[relacao]);
                }
            });
        }
        
        analized.push(atual);
    }
}

console.log("a", seller);