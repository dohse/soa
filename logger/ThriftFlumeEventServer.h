/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef ThriftFlumeEventServer_H
#define ThriftFlumeEventServer_H

#include <TProcessor.h>
#include "flume_types.h"



class ThriftFlumeEventServerIf {
 public:
  virtual ~ThriftFlumeEventServerIf() {}
  virtual void append(const ThriftFlumeEvent& evt) = 0;
  virtual void close() = 0;
};

class ThriftFlumeEventServerNull : virtual public ThriftFlumeEventServerIf {
 public:
  virtual ~ThriftFlumeEventServerNull() {}
  void append(const ThriftFlumeEvent& /* evt */) {
    return;
  }
  void close() {
    return;
  }
};

typedef struct _ThriftFlumeEventServer_append_args__isset {
  _ThriftFlumeEventServer_append_args__isset() : evt(false) {}
  bool evt;
} _ThriftFlumeEventServer_append_args__isset;

class ThriftFlumeEventServer_append_args {
 public:

  ThriftFlumeEventServer_append_args() {
  }

  virtual ~ThriftFlumeEventServer_append_args() throw() {}

  ThriftFlumeEvent evt;

  _ThriftFlumeEventServer_append_args__isset __isset;

  bool operator == (const ThriftFlumeEventServer_append_args & rhs) const
  {
    if (!(evt == rhs.evt))
      return false;
    return true;
  }
  bool operator != (const ThriftFlumeEventServer_append_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftFlumeEventServer_append_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ThriftFlumeEventServer_append_pargs {
 public:


  virtual ~ThriftFlumeEventServer_append_pargs() throw() {}

  const ThriftFlumeEvent* evt;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ThriftFlumeEventServer_close_args {
 public:

  ThriftFlumeEventServer_close_args() {
  }

  virtual ~ThriftFlumeEventServer_close_args() throw() {}


  bool operator == (const ThriftFlumeEventServer_close_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ThriftFlumeEventServer_close_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftFlumeEventServer_close_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ThriftFlumeEventServer_close_pargs {
 public:


  virtual ~ThriftFlumeEventServer_close_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ThriftFlumeEventServer_close_result {
 public:

  ThriftFlumeEventServer_close_result() {
  }

  virtual ~ThriftFlumeEventServer_close_result() throw() {}


  bool operator == (const ThriftFlumeEventServer_close_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ThriftFlumeEventServer_close_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftFlumeEventServer_close_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ThriftFlumeEventServer_close_presult {
 public:


  virtual ~ThriftFlumeEventServer_close_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ThriftFlumeEventServerClient : virtual public ThriftFlumeEventServerIf {
 public:
  ThriftFlumeEventServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ThriftFlumeEventServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void append(const ThriftFlumeEvent& evt);
  void send_append(const ThriftFlumeEvent& evt);
  void close();
  void send_close();
  void recv_close();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ThriftFlumeEventServerProcessor : virtual public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<ThriftFlumeEventServerIf> iface_;
  virtual bool process_fn(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (ThriftFlumeEventServerProcessor::*)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_append(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_close(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ThriftFlumeEventServerProcessor(boost::shared_ptr<ThriftFlumeEventServerIf> iface) :
    iface_(iface) {
    processMap_["append"] = &ThriftFlumeEventServerProcessor::process_append;
    processMap_["close"] = &ThriftFlumeEventServerProcessor::process_close;
  }

  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~ThriftFlumeEventServerProcessor() {}
};

class ThriftFlumeEventServerMultiface : virtual public ThriftFlumeEventServerIf {
 public:
  ThriftFlumeEventServerMultiface(std::vector<boost::shared_ptr<ThriftFlumeEventServerIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ThriftFlumeEventServerMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ThriftFlumeEventServerIf> > ifaces_;
  ThriftFlumeEventServerMultiface() {}
  void add(boost::shared_ptr<ThriftFlumeEventServerIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void append(const ThriftFlumeEvent& evt) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->append(evt);
    }
  }

  void close() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->close();
    }
  }

};



#endif
