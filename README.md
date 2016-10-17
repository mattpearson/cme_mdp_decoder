# cme_mdp_decoder
CME MDP Decoder Example Implementation 

This is a "starter" project showing how to subscribe to multicast groups and decode CME MDP 3.0 data on linux.
Relies on a few open source projects to work:
* [libevent](http://libevent.org/) for udp socket handling and notification (modeled after dean zhang's [simple example](https://gist.github.com/deanzhang/1777098))
* [utxx](https://github.com/saleyn/utxx) for spsc lockfree queue
* [Real Logic SBE](https://github.com/real-logic/simple-binary-encoding) for parsing CME's template into c++ code



