const express = require('express')
const app = express()

app.use(express.json())
app.use(express.urlencoded({extended:true}))

app.use(express.static('./'))

app.listen(3000,()=>{
    console.log("Servidor iniciado na porta 3000")
})







