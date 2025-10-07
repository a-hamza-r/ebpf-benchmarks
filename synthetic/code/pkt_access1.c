#include <sys/types.h>
#include <linux/bpf.h>
#include <uapi/linux/if_ether.h>
#include <uapi/linux/ip.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_endian.h>

SEC("xdp")

int packet_access(struct xdp_md* ctx) {
	void *begin = (void *)(long)ctx->data;
	void *end = (void *)(long)ctx->data_end;
	struct ethhdr * eth = begin;
	if (begin + sizeof(struct ethhdr) <= end) {
		if (bpf_ntohs(eth->h_proto) == ETH_P_IP) {
			return 0;
		}
	}
	return 1;
}

char LICENSE[] SEC("license") = "Dual BSD/GPL";