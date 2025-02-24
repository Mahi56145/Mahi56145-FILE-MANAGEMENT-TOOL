function readFile() {
    const fileInput = document.getElementById('fileInput').value;
    fetch(`http://localhost:8080/read?file=${fileInput}`)
        .then(response => response.text())
        .then(data => {
            document.getElementById('fileContent').value = data;
        })
        .catch(error => console.error('Error:', error));
}

function writeFile() {
    const fileInput = document.getElementById('fileInput').value;
    const fileContent = document.getElementById('fileContent').value;
    fetch(`http://localhost:8080/write?file=${fileInput}`, {
        method: 'POST',
        body: fileContent
    })
    .then(response => response.text())
    .then(data => {
        alert(data);
    })
    .catch(error => console.error('Error:', error));
}

function appendFile() {
    const fileInput = document.getElementById('fileInput').value;
    const fileContent = document.getElementById('fileContent').value;
    fetch(`http://localhost:8080/append?file=${fileInput}`, {
        method: 'POST',
        body: fileContent
    })
    .then(response => response.text())
    .then(data => {
        alert(data);
    })
    .catch(error => console.error('Error:', error));
}