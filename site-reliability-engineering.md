- [Marc segger's interview experience](http://blog.marc-seeger.de/2015/05/01/sre-interviews-in-silicon-valley/) : Good start to get familiar with general interview process.
```
The NALSD will be a "how would you create a application that can do ..." kind of question. 
The focus will be on things like: 
* scalability (what are your bottlenecks, Esp. Backend systems, and what would you need to scale to accommodate more users/requests) 
* Requirements/expectations you are assuming (are you going to limited by qps/bandwidth, do you need to be strictly transactional, or can you handle slightly stale data) 
* what failure conditions can happen and how to react (e.g. If the DB is down, you you have some sort of cache to handle requests for short outage, can you handle failures/timeouts for some systems by gracefully degrading and dropping certain features) 
* architecture (do you have background processes, a separate fontend/backend, how to do sharding, how are you going to handle hotspots of data)
The monitoring/alerting is going to be something like "a user is complaining of slow/failed commands, debug it", and then you go through an example of how you would walk through each step, what kinda of monitorings/logging/tooling you are expecting, etc.```
  
- [Roman Yapishev's SRE interview](https://www.keypressure.com/blog/how-i-failed-a-google-sre-interview/)
