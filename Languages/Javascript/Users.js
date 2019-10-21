const fs = require("fs");
const rc = require("seed-color");

//the actual user object

class User {
  constructor(user) {
    (this.id = user.id),
    (this.name = user.name),
    (this.ip = []);
    this.mainip = [];
    this.ip.push(user.ip);
    this.mainip.push(this.ip.toString().split(",")[0]);
    (this.pass = user.pass),
    (this.regdate = new Date());
    (this.rank = user.rank),
    (this.color = user.color),
    (this.punishments = user.punishments);
  }

  regDate() {
    return this.regdate;
  }

  hasIP(ip) {
    if (this.ip === ip) return true;
    return false;
  }

  addIP(ip) {
    if (this.ip.includes(ip)) return "already exists";
    this.ip.push(ip);
    this.mainip.push(ip.toString().split(",")[0]);
    Users.get(this.id).ip.push(ip);
    Users.signup(this, this.ip);
  }

  hasRank(rank) {
    if (this.rank == rank) return true;
    return false;
  }

  isDev() {
    if (global.developers.includes(this.id)) return true;
    return false;
  }

  isLocked() {
    if (this.punishments.includes("lock")) return true;
    return false;
  }

  isMuted() {
    if (this.punishments.includes("mute")) return true;
    return false;
  }

  isBanned() {
    if (this.punishments.includes("ban")) return true;
    return false;
  }

  deleteUser() {
    this.id = "";
    this.name = "";
    this.pass = "";
    this.ip = "";
    this.rank = "Regular";
    this.regdate = "";
  }
}

var Users = {
  data: [],
  users: [],

  importDatabase: function(roomid) {
    let file = "{}";
    try {
      file = fs.readFileSync("./databases/" + roomid + ".json").toString();
    } catch (e) {
      console.log(e.message);
    }
    this.data[roomid] = JSON.parse(file);
  },

  importDatabases: function() {
    let databases = fs.readdirSync("./databases");
    for (let i = 0, len = databases.length; i < len; i++) {
      let file = databases[i];
      if (!file.endsWith(".json")) continue;
      this.importDatabase(file.substr(0, file.indexOf(".json")));
    }
  },

  exportDatabase: function(name) {
    if (!(name in this.data)) return;
    fs.writeFileSync(
      "./databases/" + name + ".json",
      JSON.stringify(this.data[name])
        .split("},")
        .join("},\n")
    );
  },

  signup: function(details, ip) {
    let user = {
      id: details.username ? this.toId(details.username) : this.toId(details.name),
      name: details.username,
      pass: details.password,
      ip: ip,
      rank: "Regular",
      color: rc(this.id).toHex(),
      punishments: []
    };

    var newUser = new User(user);

    if (!("users" in this.data)) this.data["users"] = {};
    if (user.id in this.data["users"]) return "user already exists";
    // if(!('users' in this.data)) this.data['users'] = {};

    this.data["users"][user.id] = newUser;
    this.add(this.data["users"][user.id]);
    this.exportDatabase("users");
    console.log("done");
  },

  add: function(user) {
    // console.log(user);
    if (!user) return;
    this.users[user.id] = new User(user);
    // console.log(this.users[user.id]);
    return this.get(user.id);
  },

  get: function(usr) {
    if (!(usr in this.users)) return console.log("Not registered");
    var user = this.users[usr];
    return user;
  },

  getUserByIP: function(ip) {
    let users = Object.keys(this.users);
    ip = ip.split(",")[0];
    for (let i = 0; i < users.length; i++) {
      if (this.users[users[i]].mainip.includes(ip)) return this.users[users[i]];
    }
  },

  importUsers: function() {
    if (!this.data["users"]) return console.log("No users registered");
    let users = Object.keys(this.data["users"]);
    for (let i = 0; i < users.length; i++) {
      this.add(this.data["users"][users[i]]);
    }
    console.log("Successfully imported users");
  },

  toId: function(str) {
    return str.replace(/[^A-Z0-9]/gi, "").toLowerCase();
  }
};

module.exports = Users;
