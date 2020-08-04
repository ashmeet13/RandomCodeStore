from flask import Flask, jsonify, request

app = Flask(__name__) 
  

@app.route("/parse", methods=["POST"])
def parse():
    content = request.get_json()
    name = content['name']
    message = f"Heroku Got {name}"
    return jsonify({'message':message})
  
if __name__ == '__main__': 
    app.run() 