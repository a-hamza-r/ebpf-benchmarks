#include <sys/types.h>
#include <linux/bpf.h>
#include <uapi/linux/if_ether.h>
#include <linux/ip.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_endian.h>

SEC("xdp")

unsigned char pkt_refinements(struct xdp_md * ctx) {
   void * begin = (void *)(long)ctx->data;
   void * end = (void *)(long)ctx->data_end;
   void * ptr = begin;
   unsigned char protocol;
   if (ptr + sizeof(struct ethhdr) <= end) {
      struct ethhdr * eth = ptr;
      if (bpf_ntohs(eth->h_proto) == ETH_P_IP) {
         ptr = ptr + sizeof(struct ethhdr);
         struct iphdr * ip = ptr;
         if (ptr + sizeof(struct iphdr) <= end) {
            protocol = ip->protocol;
            ptr = ptr + sizeof(struct iphdr);
         } else {
            protocol = 1;
         }
      } else {
         protocol = 2;
      }
   } else {
      protocol = 3;
   }
   return protocol;
}

char LICENSE[] SEC("license") = "Dual BSD/GPL";
